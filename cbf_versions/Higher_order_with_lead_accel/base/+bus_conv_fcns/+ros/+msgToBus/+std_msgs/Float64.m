function slBusOut = Float64(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    slBusOut.Data = double(msgIn.Data);
end
