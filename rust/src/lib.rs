mod stack_entry;
mod table;
mod ffi;

use libc::{signal, c_int};
use backtrace::Backtrace;
use stack_entry::StackEntry;
use crate::ffi::stack_entry_ffi::StackEntryFFI;
use crate::table::print_table;

fn internal_get_stacktrace() -> Vec<StackEntry> {
    let bt = Backtrace::new();
    let mut entries : Vec<StackEntry> = Vec::new();
    for frame in bt.frames() {
        for symbol in frame.symbols() {
            entries.push( StackEntry::from_backtrace_symbol(symbol) );
        }
    }
    entries
}

#[unsafe(no_mangle)]
pub extern "C" fn get_stacktrace(out_len: &mut usize) -> *mut StackEntryFFI {

    let mut entries_ffi: Vec<_> = internal_get_stacktrace().iter().map(StackEntryFFI::from).collect();

    let ptr = entries_ffi.as_mut_ptr();
    *out_len = entries_ffi.len();
    std::mem::forget(entries_ffi);
    ptr
}

#[unsafe(no_mangle)]
pub extern "C" fn free_stacktrace(ptr: *mut StackEntryFFI, len: usize) {
    if ptr.is_null() || len == 0 {
        return;
    }
    unsafe {
        let _ = Vec::from_raw_parts(ptr, len, len);
    }
}

extern "C" fn handler(sig: c_int) {
    eprintln!("Caught signal: {}", sig);
    print_stacktrace();
    std::process::exit(1);
}


#[unsafe(no_mangle)]
pub extern "C" fn print_stacktrace() {
    let entries = internal_get_stacktrace();
    print_table(entries.as_slice(), 128);
}

#[unsafe(no_mangle)]
pub extern "C" fn setup_one_signal_handler(sig : c_int) -> bool {
    unsafe {
        if signal(sig, handler as usize) == libc::SIG_ERR {
            eprintln!("Error setting up signal handler for SIGSEGV");
            return false
        }
        true
    }
}

pub fn setup_signal_handlers(signals : Vec<c_int>) {
    for &sig in signals.iter() {
        if !setup_one_signal_handler(sig) {
            eprintln!("Failed to set up handler for signal: {}", sig);
        }
    }
}
