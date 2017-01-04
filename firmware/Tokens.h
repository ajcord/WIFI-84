#pragma once

namespace Token {
    enum Token {
        Invalid     = 0x00,
        Connected   = 0x7e06,
        Select      = 0xbb58,
        For         = 0xd3,
        Stop        = 0xd9,
        Menu        = 0xe6,
        Send        = 0xe7,
        Get         = 0xe8,
    };
};
