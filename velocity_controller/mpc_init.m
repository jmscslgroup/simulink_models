clear;
%% create MPC controller object with sample time
A = [0, 1; 0, -1.566];
B = [0; 1.745];
C = [1, 0; 0, 1];
D = [0; 0];
sys = ss(A, B, C, D);
mpc_obj = mpc(sys, 0.05);
%% specify prediction horizon
mpc_obj.PredictionHorizon = 10;
%% specify control horizon
mpc_obj.ControlHorizon = 2;
%% specify nominal values for inputs and outputs
mpc_obj.Model.Nominal.U = 0;
mpc_obj.Model.Nominal.Y = [0;0];
%% specify constraints for MV and MV Rate
mpc_obj.MV(1).Min = -3;
mpc_obj.MV(1).Max = 1.5;
%% specify overall adjustment factor applied to weights
beta = 3.0649;
%% specify weights
mpc_obj.Weights.MV = 0.393320847635822*beta;
mpc_obj.Weights.MVRate = 0.317806698402466/beta;
mpc_obj.Weights.OV = [2.35992508581493 0.589981271453733]*beta;
mpc_obj.Weights.ECR = 100000;
