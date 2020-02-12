std::map<std::string, mstch::node> specs_lambdas{
        {"Interpolation", mstch::lambda_wrapper{{[](const std::string&) -> mstch::node {
             return std::string{"world"};
         }}}},
        {"Interpolation - Expansion",
         mstch::lambda_wrapper{{[](const std::string&) -> mstch::node {
             return std::string{"{{planet}}"};
         }}}},
        {"Interpolation - Alternate Delimiters",
         mstch::lambda_wrapper{{[](const std::string&) -> mstch::node {
             return std::string{"|planet| => {{planet}}"};
         }}}},
        {"Interpolation - Multiple Calls",
         mstch::lambda_wrapper{{[](const std::string&) -> mstch::node {
             static int calls = 0;
             return ++calls;
         }}}},
        {"Escaping", mstch::lambda_wrapper{{[](const std::string&) -> mstch::node {
             return std::string{">"};
         }}}},
        {"Section", mstch::lambda_wrapper{{[](const std::string& txt) -> mstch::node {
             return std::string{(txt == "{{x}}") ? "yes" : "no"};
         }}}},
        {"Section - Expansion",
         mstch::lambda_wrapper{{[](const std::string& txt) -> mstch::node {
             return txt + std::string{"{{planet}}"} + txt;
         }}}},
        {"Section - Alternate Delimiters",
         mstch::lambda_wrapper{{[](const std::string& txt) -> mstch::node {
             return txt + std::string{"{{planet}} => |planet|"} + txt;
         }}}},
        {"Section - Multiple Calls",
         mstch::lambda_wrapper{
                 {[](const std::string& txt) -> mstch::node { return "__" + txt + "__"; }}}},
        {"Inverted Section",
         mstch::lambda_wrapper{{[](const std::string&) -> mstch::node { return false; }}}}};
