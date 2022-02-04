#!/bin/bash

echo "Starting program at $(date)" # Date will be substituted
echo ""
echo "Running program $0 with $# arguments with pid $$"
echo ""

for file in test_maps/*.fdf; do
	./fdf "./$file" &
done
