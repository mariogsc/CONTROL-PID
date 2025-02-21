%% DC MOTOR CONTROL - PID vs FOPID

% Configuración de propiedades comunes
font_size = 9; % Tamaño de fuente fijo
line_width = 1; % Grosor de línea fijo

% Configuración del tamaño
height = 8;
width = 5;

% Muestras
ini_muestras = 0/0.01 + 1; % Index for the start of the samples
num_muestras = 80 / 0.01 ; % Total number of samples

%% Cargar datos
% pid = load("pid_velocity_noise.mat");
% fopid07 = load("fopid07_velocity_noise.mat");
% fopid1 = load("fopid1_velocity_noise.mat");
% 
% % Extraer datos
% time = pid.pid_velocity_noise.time(ini_muestras:num_muestras, 1)';
% ref = pid.pid_velocity_noise.signals.values(ini_muestras:num_muestras, 1)';
% 
% pid_velocity = pid.pid_velocity_noise.signals.values(ini_muestras:num_muestras, 2)';
% fopid07_velocity = fopid07.fopid_velocity_noise.signals.values(ini_muestras:num_muestras, 2)';
% fopid1_velocity = fopid1.fopid_velocity_noise.signals.values(ini_muestras:num_muestras, 2)';
% 
% pid_input = pid.pid_velocity_noise.signals.values(ini_muestras:num_muestras, 3)';
% fopid07_input = fopid07.fopid_velocity_noise.signals.values(ini_muestras:num_muestras, 3)';
% fopid1_input = fopid1.fopid_velocity_noise.signals.values(ini_muestras:num_muestras, 3)';
% 
% %% Generar graficas para velocidades
% figure('Position', [100, 100, width*100, height*100]); % Tamaño de la figura
% plot(time, pid_velocity, 'DisplayName', 'PID', 'Color', [0 0.4470 0.7410], 'LineWidth', line_width);
% hold on;
% %plot(time, fopid1_velocity, 'DisplayName', 'FO-PID $\lambda = \mu = 1$', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
% plot(time, fopid07_velocity, 'DisplayName', 'FO-PID', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
% plot(time, ref, '--k', 'DisplayName', 'Referencia', 'LineWidth', line_width);
% 
% % Configuración de ejes
% xlabel('Tiempo (s)', 'FontSize', font_size, 'Interpreter', 'latex');
% ylabel('$\omega$ (rpm)', 'Interpreter', 'latex'); 
% legend('Location', 'northeast', 'Interpreter', 'latex'); 
% box off; % Quitar el recuadro
% grid on;
% set(gca, 'XColor', 'k', 'YColor', 'k'); 
% set(gca, 'TickDir', 'out', 'FontSize', font_size);
% ylim([-20, 100]);
% 
% % Ajustar el tamaño de la figura
% set(gcf, 'Units', 'centimeters'); % Cambiar la unidad de la figura a centímetros
% set(gcf, 'Position', [1, 1, height, width]); % Ajustar el tamaño de la figura (ancho, alto) en centímetros
% 
% 
% %% Generar graficas para entradas
% figure('Position', [100, 100, width*100, height*100]); % Tamaño de la figura
% plot(time, pid_input, 'DisplayName', 'PID', 'Color', [0 0.4470 0.7410], 'LineWidth', line_width);
% hold on;
% %plot(time, fopid1_input, 'DisplayName', 'FO-PID $\lambda = \mu = 1$', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
% hold on;
% plot(time, fopid07_input, 'DisplayName', 'FO-PID', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
% 
% % Configuración de ejes
% xlabel('Tiempo (s)', 'FontSize', font_size, 'Interpreter', 'latex');
% ylabel('PWM', 'FontSize', font_size, 'Interpreter', 'latex'); 
% legend('Location', 'northeast', 'Interpreter', 'latex'); 
% box off; % Quitar el recuadro
% grid on;
% set(gca, 'XColor', 'k', 'YColor', 'k'); 
% set(gca, 'TickDir', 'out', 'FontSize', font_size);
% ylim([-300, 400]);
% 
% % Ajustar el tamaño de la figura
% set(gcf, 'Units', 'centimeters'); % Cambiar la unidad de la figura a centímetros
% set(gcf, 'Position', [1, 1, height, width]); % Ajustar el tamaño de la figura (ancho, alto) en centímetros



%% Gráficas control de posición 

pid = load("grafica_angulo_pid.mat");
fopid = load("grafica_angulo_fopid_final.mat");
fopid03 = load("grafica_angulo_fopid03.mat");

sim = load("grafica_angulo_simulacion.mat");

pid = pid.pid.data;
fopid = fopid.angle_fopid_final;
% fopid03 = fopid03.angle_fopid03;

% Extraer datos
time = pid.time(ini_muestras:num_muestras, 1)';
ref = pid.signals.values(ini_muestras:num_muestras, 1)';

pid_angle = pid.signals.values(ini_muestras:num_muestras, 2)';
fopid_angle = fopid.signals.values(ini_muestras:num_muestras, 2)';
pid_sim = sim.out.grafica_angle_simulacion_fopid03(ini_muestras:num_muestras, 2);
fopid_sim = sim.out.grafica_angle_simulacion_fopid03(ini_muestras:num_muestras, 2);
%fopid03_angle = fopid03.signals.values(ini_muestras:num_muestras, 2)';

pid_input = pid.signals.values(ini_muestras:num_muestras, 3)';
fopid_input = fopid.signals.values(ini_muestras:num_muestras, 3)';
%fopid03_input = fopid03.signals.values(ini_muestras:num_muestras, 3)';

% ---------- Generar graficas para ángulo ----------
figure('Position', [100, 100, width*100, height*100]); % Tamaño de la figura
plot(time, pid_angle, 'DisplayName', 'PID', 'Color', [0 0.4470 0.7410], 'LineWidth', line_width);
hold on;
%plot(time, fopid03_angle, 'DisplayName', 'FO-PID $0.3$', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
plot(time, fopid_angle, 'DisplayName', 'FO-PID', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
plot(time, ref, '--k', 'DisplayName', 'Referencia', 'LineWidth', line_width);

% Configuración de ejes
xlabel('Tiempo (s)', 'FontSize', font_size, 'Interpreter', 'latex');
ylabel('$\theta$ (deg)', 'Interpreter', 'latex'); 
legend('Location', 'northeast', 'Interpreter', 'latex'); 
box off; % Quitar el recuadro
grid on;
set(gca, 'XColor', 'k', 'YColor', 'k'); 
set(gca, 'TickDir', 'out', 'FontSize', font_size);
ylim([-300, 1000]);

% Ajustar el tamaño de la figura
set(gcf, 'Units', 'centimeters'); % Cambiar la unidad de la figura a centímetros
set(gcf, 'Position', [1, 1, height, width]); % Ajustar el tamaño de la figura (ancho, alto) en centímetros
set(gca, 'TickLabelInterpreter', 'latex');

%% Generar graficas para entradas
figure('Position', [100, 100, width*100, height*100]); % Tamaño de la figura
plot(time, pid_input, 'DisplayName', 'PID', 'Color', [0 0.4470 0.7410], 'LineWidth', line_width);
hold on;
plot(time, fopid_input, 'DisplayName', 'FO-PID', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);
hold on;
%plot(time, fopid03_input, 'DisplayName', 'FO-PID $0.3$', 'Color', [0.8500 0.3250 0.0980], 'LineWidth', line_width);

% Configuración de ejes
xlabel('Tiempo (s)', 'FontSize', font_size, 'Interpreter', 'latex');
ylabel('PWM', 'FontSize', font_size, 'Interpreter', 'latex'); 
legend('Location', 'northeast', 'Interpreter', 'latex'); 
box off; % Quitar el recuadro
grid on;
set(gca, 'XColor', 'k', 'YColor', 'k'); 
set(gca, 'TickDir', 'out', 'FontSize', font_size);
ylim([-300, 500]);

% Ajustar el tamaño de la figura
set(gcf, 'Units', 'centimeters'); % Cambiar la unidad de la figura a centímetros
set(gcf, 'Position', [1, 1, height, width]); % Ajustar el tamaño de la figura (ancho, alto) en centímetros
set(gca, 'TickLabelInterpreter', 'latex');
