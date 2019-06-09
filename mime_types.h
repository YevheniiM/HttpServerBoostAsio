//
// Created by Yevhenii on 20/05/2019.
//

#ifndef BOOST_ACIO_EXAMPLE_MIME_TYPES_H
#define BOOST_ACIO_EXAMPLE_MIME_TYPES_H

#include <string>

namespace http {
    namespace server3 {
        namespace mime_types {

/// Convert a file extension into a MIME type.
            std::string extension_to_type(const std::string& extension);

        } // namespace mime_types
    } // namespace server3
} // namespace http

#endif //BOOST_ACIO_EXAMPLE_MIME_TYPES_H
