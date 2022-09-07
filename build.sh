#!/bin/bash
rm -rf ./build/* && cd build && cmake .. && make && cd .. && ./build/demo
