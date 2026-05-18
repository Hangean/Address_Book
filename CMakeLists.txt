cmake_minimum_required(VERSION 4.2)
project(Address_Book)

set(CMAKE_CXX_STANDARD 20)

add_executable(Address_Book main.cpp
        Contact.h
        Contact.cpp
        AddressBook.h
        AddressBook.cpp)
