#pragma once

#include <rtrp/objects/CreatorObject.hpp>
#include <rtrp/objects/LevelObject.hpp>
#include <rtrp/objects/SongObject.hpp>
#include <rtrp/objects/PageObject.hpp>

#define DEFINE_EQUALITY_OP(type) \
    inline bool operator==(const type& lhs, const type& rhs) { return lhs == rhs; }

DEFINE_EQUALITY_OP(rtrp::objects::LevelObject);
DEFINE_EQUALITY_OP(rtrp::objects::CreatorObject);
DEFINE_EQUALITY_OP(rtrp::objects::SongObject);
DEFINE_EQUALITY_OP(rtrp::objects::PageObject);

#undef DEFINE_EQUALITY_OP
