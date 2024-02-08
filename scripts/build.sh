#!/bin/bash

vendor/premake5/premake5 gmake2
make config=$1
