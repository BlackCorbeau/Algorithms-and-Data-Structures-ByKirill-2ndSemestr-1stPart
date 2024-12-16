// Copyright 2024 Kirill Remizov

#pragma once
#ifndef LIB_PARSER_LIB_PARSER_HEDER_H_
#define LIB_PARSER_LIB_PARSER_HEDER_H_

#include "../lib_CString/CString.h"
#include "../lib_list/List.h"

bool is_correct(const CString* exp);

template<typename T>
bool RabbitandTurtleCycleList(const TList<T>& list);

#endif  // LIB_PARSER_LIB_PARSER_HEDER_H_
