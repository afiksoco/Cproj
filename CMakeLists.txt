cmake_minimum_required(VERSION 3.28)
project(Cproj C)

set(CMAKE_C_STANDARD 11)

add_executable(Cproj main.c
        Address.c
        Date.c
        Facility.c
        General.c
        Guest.c
        Hotel.c
        HotelSystem.c
        Reservation.c
        Review.c
        Room.c
        List.c
        Review.h
)
