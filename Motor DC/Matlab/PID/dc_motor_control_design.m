% DC MOTOR

tf_motor=tf([0.2321],[0.09214 0.6075 1]);

%% Ident results
G1=tf(0.02349,[1 0.07082]);
%G1_old=tf(0.2875,[1 1.449]);
G2=tf(1.385,[1 4.975 6.98]);
%G1=tf(0.3145,[1 1.876]);

G_pos = tf(8.294,[1 7.555 1.146]);
G_vel = tf([5.076 0],[1 4.48 0.4322]);
%% pid vel
kp_vel=7;
ki_vel=31;
kd_vel=9;

%% pid_pos
kp_pos=19;
ki_pos=10;
kd_pos=1;
%% Comparación pid vs fopid  

% Configuración del tamaño
height = 10;
width = 6;

% Configuración de propiedades comunes
font_size = 8; % Tamaño de fuente fijo
line_width = 1; % Grosor de línea fijo

%% POSICIÓN
pid_pos_normal = pid(kp_pos,ki_pos,kd_pos);
%pid_vel_fracc = fpid(kp,ki,kd,0.7,0.7);
load("fopid03_pos.mat");

G_vel_feed=feedback(pid_pos_normal*G_pos,1);
G_fracc=feedback(fopid03_pos*G_pos,1);
figure;
step(G_fracc);

pid_pos_normal = pid(kp_pos,ki_pos,kd_pos);
G_pos_feed=feedback(pid_pos_normal*G_pos,1);
figure;
step(G_pos_feed);

figure;
bode(G_pos_feed); hold on;
fbode(G_fracc);
legend('PID', 'FO-PID', 'Location', 'southeast', 'Interpreter', 'latex');
box off;
grid on;
set(gca, 'XColor', 'k', 'YColor', 'k'); % Asegurar que los ejes X e Y sean visibles
set(gca, 'TickDir', 'out'); % Poner las marcas fuera de la gráfica
set(findall(gcf, 'type', 'text'), 'FontSize', font_size); % Establecer tamaño de fuente para textos
set(findall(gcf, 'type', 'axes'), 'FontSize', font_size); % Establecer tamaño de fuente para ejes
% Ajustar el tamaño de la figura
set(gcf, 'Units', 'centimeters'); 
set(gcf, 'Position', [1, 1, height, width]);

%% VELOCIDAD
% pid_vel_normal = pid(kp_vel,ki_vel,kd_vel);
% %pid_vel_fracc = fpid(kp,ki,kd,0.7,0.7);
% load("pid_fracc.mat");
% 
% G_vel_feed=feedback(pid_vel_normal*G_vel,1);
% G_fracc=feedback(pid_fracc*G1,1);
% figure;
% step(G_vel_feed);
% 
% pid_pos_normal = pid(kp_pos,ki_pos,kd_pos);
% G_pos_feed=feedback(pid_vel_normal*G_pos,1);
% figure;
% step(G_pos_feed);

% figure;
% bode(pid_normal); hold on;
% fbode(pid_fracc);
% legend('PID', 'FO-PID', 'Location', 'southeast', 'Interpreter', 'latex');
% box off;
% grid on;
% set(gca, 'XColor', 'k', 'YColor', 'k'); % Asegurar que los ejes X e Y sean visibles
% set(gca, 'TickDir', 'out'); % Poner las marcas fuera de la gráfica
% set(findall(gcf, 'type', 'text'), 'FontSize', font_size); % Establecer tamaño de fuente para textos
% set(findall(gcf, 'type', 'axes'), 'FontSize', font_size); % Establecer tamaño de fuente para ejes
% % Ajustar el tamaño de la figura
% set(gcf, 'Units', 'centimeters'); 
% set(gcf, 'Position', [1, 1, height, width]);

