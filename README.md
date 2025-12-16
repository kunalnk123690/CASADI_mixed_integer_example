# CASADI_mixed_integer_example
This example shows how to use the CASADI library (https://github.com/casadi/casadi) to solve a simple mixed integer (linear) program of the form

```math
\min_{x} g^{T}x 
```

```math
Ax \preceq b
```

```math
x \geq 0 
```

with $x = \begin{bmatrix} x_1 \\ x_2 \end{bmatrix}$, $x_1 \in \mathbb{R}$, $x_2 \in \mathbb{Z}$, 
$`g = \begin{bmatrix} -3 \\ -2 \end{bmatrix}`$, 
$`A = \begin{bmatrix} 4 & 2 \\ 1 & 2 \\ 1 & 1 \end{bmatrix}`$ 
and 
$`b = \begin{bmatrix} 15 \\ 8 \\ 5 \end{bmatrix}`$. The source has two files solving the same optimization program with example1.cpp using CASADI-Optistack and example2.cpp using nlpsol. Both return the same optimal value $x^* = \begin{bmatrix} 2.75 \\ 2 \end{bmatrix}$.

## Without Docker:
First, install Eigen
```
sudo apt install libeigen3-dev
```
and CasADi
```
pip install casadi
```
Once installed, build the code using CMake:
```
mkdir build && cd build
cd build
make -j$(nproc)
```

## With Docker:
Run the script `run_docker.sh`. It will build the docker image. Navigate to `/home/Casadi_mixed_integer/Casadi_mixed_integer_ws` and follow the same instructions of building using CMake (The docker image has everything installed).