message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(doxygen)
find_package(nlohmann_json)
find_package(cryptopp)
find_package(cmake)
find_package(GTest)
find_package(cpprestsdk)
find_package(Boost)
find_package(OpenSSL)

set(CONANDEPS_LEGACY  doxygen::doxygen  nlohmann_json::nlohmann_json  cryptopp::cryptopp  cmake::cmake  gtest::gtest  cpprestsdk::cpprestsdk  boost::boost  openssl::openssl )