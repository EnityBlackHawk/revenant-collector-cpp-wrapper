#pragma once

#include <vector>

#include "model/userdatadesc.h"
#include "model/userdatavalue.h"


class UserDataService
{

public:
    UserDataService(const std::vector<Revenant::UserDataDesc>& descs);
    std::vector<UserDataValue> process();


private:
    const std::vector<Revenant::UserDataDesc>& _descs;



};