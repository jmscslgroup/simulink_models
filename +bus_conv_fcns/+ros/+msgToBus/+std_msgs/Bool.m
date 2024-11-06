function slBusOut = Bool(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    slBusOut.Data = logical(msgIn.Data);
end
