#!/bin/bash

# Clear terminal (optional)
clear

# 1. Targeted Build Cache Cleanup
# Use `builder prune` instead of `system prune` to only remove build cache and not other project images/networks.
echo "Pruning Docker build cache..."
docker builder prune -f

# 2. Build the Docker Image
echo "Building casadi-mixed-integer image..."
# Use an explicit build context variable for clarity and robustness
BUILD_CONTEXT=$(pwd)
DOCKERFILE_PATH=".devcontainer/Dockerfile"
IMAGE_NAME="casadi-mixed-integer"

docker build -t $IMAGE_NAME -f $DOCKERFILE_PATH $BUILD_CONTEXT

# Check if build was successful
if [ $? -ne 0 ]; then
  echo "Docker build failed. Exiting."
  exit 1
fi

# 3. Run the Container
echo "Running container and mounting current directory..."
PROJECT_MOUNT_PATH="/home/Casadi_mixed_integer/Casadi_mixed_integer_ws"

docker run -it --rm \
  -v $BUILD_CONTEXT:$PROJECT_MOUNT_PATH \
  $IMAGE_NAME \
  bash