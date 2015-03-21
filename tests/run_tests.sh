#!/bin/bash
for test in `ls bin/*.gtest`
do
	./$test
done
