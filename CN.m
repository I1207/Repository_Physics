function y = CN(T, eta, N)
% This function calculates the temperature distribution at the next time step
% using the Crank-Nicolson method.

% Coefficients for the tridiagonal matrix
a = -1;
c = -1;
d = (2 / eta) + 2;

% Initialize the right-hand side vector
b = ones(N - 2, 1);

% Calculate the elements of the right-hand side vector
for i = 2:N - 1
    b(i - 1) = T(i - 1) + (2 / eta - 2) * T(i) + T(i + 1);
end

% Update boundary conditions
b(1) = b(1) + T(1);
b(N - 2) = b(N - 2) + T(N);

% Create the tridiagonal matrix M
M = diag(a .* ones(1, N - 3), 1) + diag(d .* ones(1, N - 2)) + diag(c .* ones(1, N - 3
