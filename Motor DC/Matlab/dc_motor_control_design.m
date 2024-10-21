% DC MOTOR

tf_motor=tf([0.2321],[0.09214 0.6075 1]);

%% Ident results
G1=tf(0.2875,[1 1.449]);
G2=tf(1.385,[1 4.975 6.98]);
G1_dis=tf([0.00242 0], [1 -0.9878],0.01);
G2_dis=tf([0.0001143 0 0], [1 -1.956 0.9561],0.01);

%% pid 
kp=75;
ki=38.12;
kd=35;
pid_motor = pid(kp,ki,kd);
G=feedback(pid_motor*G2,1);
step(G);hold on;
step(G1);
%% pid funciona
kp=9;
ki=7.2;
kd=12;
pid_motor = pid(kp,ki,kd);
G=feedback(pid_motor*G1,1);
step(G);hold on;
% step(G1);
%% fpid_optim
kp_fracc=70.2146;
ki_fracc=19.051;
kd_fracc=33.9457;
lambda=0.998;
mu=0.992;
