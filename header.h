//
// Created by Yevhenii on 20/05/2019.
//

#ifndef BOOST_ACIO_EXAMPLE_HEADER_H
#define BOOST_ACIO_EXAMPLE_HEADER_H

#include <string>

namespace http {
    namespace server3 {

        struct header
        {
            std::string name;
            std::string value;
        };

    } // namespace server3
} // namespace http


#endif //BOOST_ACIO_EXAMPLE_HEADER_H
