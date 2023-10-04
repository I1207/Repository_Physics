function HeatScheme
% This function simulates heat diffusion over time.

% Physical parameters
eta = 0.2;    % Thermal diffusivity
L = 0.5;      % Length of the domain
kappa = 10;   % Heat conductivity

% Delta x, Delta t calculation
N = 101;               % Number of spatial points
x = linspace(0.0, L, N);  % Spatial domain
dx = x(2) - x(1);       % Spatial step size
dt = (eta * dx^2) / kappa;  % Time step size

% Initial heat pulse
T0 = 20;          % Initial temperature
DeltaT = 80;      % Change in temperature
T = ones(N, 1) * T0;
T((N-1)/2 + 1) = T0 + DeltaT;  % Adding a heat pulse in the middle

% Time evolution loop
t = 0;
tend = 1000 * dt;

while t < tend
    plot(x, T);  % Plot the current temperature distribution

    T(N) = T0;   % Boundary conditions
    T(1) = T0;
    % ... (Crank-Nicolson or inverse matrix method)
    T(2:N-1) = CN(T, eta, N);  % Calculate the new temperature values

    drawnow limitrate  % Refresh the plot (commented out pause function)

    t = t + dt;  % Increment time
end

hold on
z = sqrt(2 * kappa * t);  % Calculate the standard deviation (sigma)

% Define a Gaussian distribution for the initial heat pulse
G = @(x) (T0 + (DeltaT * dx * (1 / (sqrt(2 * pi * z.^2))) * exp((-(x - 0.25).^2) / (2 * z.^2))));
plot(x, G(x));  % Plot the Gaussian distribution

hold off
end
