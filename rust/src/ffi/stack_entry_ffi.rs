use std::ffi::CString;
use std::os::raw::c_char;

#[repr(C)]
pub struct StackEntryFFI {
    pub name: *const c_char,
    pub file: *const c_char,
    pub line: *const c_char,
}

impl StackEntryFFI {
    pub fn from_owned_cstrings(name: CString, file: CString, line: CString) -> Self {
        StackEntryFFI{
            name: name.into_raw(),
            file: file.into_raw(),
            line: line.into_raw(),
        }
    }
}

impl From<&crate::stack_entry::StackEntry> for StackEntryFFI {
    fn from(entry: &crate::stack_entry::StackEntry) -> Self {
        let name = CString::new(entry.name()).unwrap_or_default();
        let file = CString::new(entry.file()).unwrap_or_default();
        let line = CString::new(entry.line()).unwrap_or_default();
        StackEntryFFI::from_owned_cstrings(name, file, line)
    }
}


#[cfg(test)]
mod tests {
    use std::ffi::{c_char, CString};

    #[test]
    fn test_stack_entry_ffi() {
        use crate::stack_entry::StackEntry;
        use super::StackEntryFFI;

        let entry = StackEntry::new(
            "function_name".to_string(),
            "/path/to/file.rs".to_string(),
            "42".to_string(),
        );

        let entry_ffi = StackEntryFFI::from(&entry);

        unsafe {
            assert_eq!(std::ffi::CStr::from_ptr(entry_ffi.name).to_str().unwrap(), "function_name");
            assert_eq!(std::ffi::CStr::from_ptr(entry_ffi.file).to_str().unwrap(), "/path/to/file.rs");
            assert_eq!(std::ffi::CStr::from_ptr(entry_ffi.line).to_str().unwrap(), "42");
        }
    }

    #[test]
    fn test_from_stack_entry() {
        use crate::stack_entry::StackEntry;
        use super::StackEntryFFI;

        let entry = StackEntry::new(
            "my_function".to_string(),
            "src/main.rs".to_string(),
            "100".to_string(),
        );
        
        let entry_ffi: StackEntryFFI = StackEntryFFI::from(&entry);

        unsafe {
            assert_eq!(std::ffi::CStr::from_ptr(entry_ffi.name).to_str().unwrap(), "my_function");
            assert_eq!(std::ffi::CStr::from_ptr(entry_ffi.file).to_str().unwrap(), "src/main.rs");
            assert_eq!(std::ffi::CStr::from_ptr(entry_ffi.line).to_str().unwrap(), "100");
            
            let _ = CString::from_raw(entry_ffi.name as *mut c_char);
            let _ = CString::from_raw(entry_ffi.file as *mut c_char);
            let _ = CString::from_raw(entry_ffi.line as *mut c_char);
        }
    }

}
