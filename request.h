//
// Created by Yevhenii on 20/05/2019.
//

#ifndef BOOST_ACIO_EXAMPLE_REQUEST_H
#define BOOST_ACIO_EXAMPLE_REQUEST_H

#include <string>
#include <vector>
#include "header.h"

namespace http {
    namespace server3 {

/// A request received from a client.
        struct request
        {
            std::string method;
            std::string uri;
            int http_version_major;
            int http_version_minor;
            std::vector<header> headers;
        };

    } // namespace server3
} // namespace http


#endif //BOOST_ACIO_EXAMPLE_REQUEST_H
