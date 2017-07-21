#!/bin/bash
rm -rf ./proto_lua/*
rm -rf ./proto_cpp/*
protoc --plugin=./plugin/protoc-gen-lua --proto_path=./proto_file/ --lua_out=./proto_lua/ ./proto_file/*.proto
protoc --cpp_out=./proto_cpp --proto_path=./proto_file ./proto_file/*.proto