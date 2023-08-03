# CASADI_mixed_integer_example
This example shows how to use the CASADI library (https://github.com/casadi/casadi) to solve a simple mixed integer (linear) program of the form

$$ \displaystyle \min_{x} g^{T}x $$

$$ Ax \preceq b $$

$$  x \geq 0 $$

with $' g = \begin{bmatrix} -3 \\ -2 \end{bmatrix} '$, $A = \begin{bmatrix} 4 & 2 \\ 1 & 2 \\ 1 & 1 \end{bmatrix}$ and $b = \begin{bmatrix} 15 \\ 8 \\ 5 \end{bmatrix}$. This example uses BONMIN solver so make sure you have CASADI compiled from source and installed with BONMIN flag on.
