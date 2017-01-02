#pragma once

// TODO: compress tables, maybe by splitting the second level into two levels,
// indexing on nibbles rather than bytes

#if TOKEN_TABLE_SYS_VARS
const char* tokenTable5C[257] = {
   (char*)0xffffffff, // Denotes that this is a table, not a string
    "[A]", "[B]", "[C]", "[D]", "[E]", "[F]", "[G]", "[H]", "[I]", "[J]", NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTable5D[257] = {
   (char*)0xffffffff,
    "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "L0", NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTable5E[257] = {
   (char*)0xffffffff,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    "Y1", "Y2", "Y3", "Y4", "Y5", "Y6", "Y7", "Y8", "Y9", "Y0", NULL, NULL, NULL, NULL, NULL, NULL,
    "X1T", "Y1T", "X2T", "Y2T", "X3T", "Y3T", "X4T", "Y4T", "X5T", "Y5T", "X6T", "Y6T", NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    "r1", "r2", "r3", "r4", "r5", "r6", "u", "v", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    "u", "v", "w", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTable60[257] = {
   (char*)0xffffffff,
    "Pic1", "Pic2", "Pic3", "Pic4", "Pic5", "Pic6", "Pic7", "Pic8", "Pic9", "Pic0", NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTable61[257] = {
   (char*)0xffffffff,
    "GDB1", "GDB2", "GDB3", "GDB4", "GDB5", "GDB6", "GDB7", "GDB8", "GDB9", "GDB0", NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTable62[257] = {
   (char*)0xffffffff,
    NULL, "RegEq", "n", "xbar", "Sigma x", "Sigma x^2", "Sx", "sigma x", "minX", "maxX", "minY", "maxY", "ybar", "Sigma y", "Sigma y^2", "Sy",
    "sigma y", "Sigma xy", "r", "Med", "Q1", "Q3", "a", "b", "c", "d", "e", "x1", "x2", "x3", "y1", "y2",
    "y3", "n", "p", "z", "t", "chi^2", "F", "df", "phat", "p1hat", "p2hat", "x1bar", "Sx1", "n1", "x2bar", "Sx2",
    "n2", "Sxp", "lower", "upper", "s", "r^2", "R^2", "Factor df", "Factor SS", "Factor MS", "Error df", "Error SS", "Error MS", NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTable63[257] = {
   (char*)0xffffffff,
    "ZXscl", "ZYscl", "Xscl", "Yscl", "u(nMin)", "v(nMin)", "u(n-1)", "v(n-1)", "Zu(nMin)", "Zv(nMin)", "Xmin", "Xmax", "Ymin", "Ymax", "Tmin", "Tmax",
    "thetamin", "thetamax", "ZXmin", "ZXmax", "ZYmin", "ZYmax", "Zthetamin", "Zthetamax", "ZTmin", "ZTmax", "TblMin", "nMin", "ZnMin", "nMax", "ZnMax", "nMin",
    "ZnMin", "deltaTbl", "Tstep", "thetastep", "ZTstep", "Zthetastep", "deltaX", "deltaY", "XFact", "YFact", "TblInput", "N", "I%", "PV", "PMT", "FV",
    "P/Y", "C/Y", "w(nMin)", "Zw(nMin)", "PlotStep", "ZPlotStep", "Xres", "ZXres", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* tokenTableAA[257] = {
    (char*)0xffffffff,
    "Str1", "Str2", "Str3", "Str4", "Str5", "Str6", "Str7", "Str8", "Str9", "Str0", NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};
#else
const char* tokenTable5C = NULL;
const char* tokenTable5D = NULL;
const char* tokenTable5E = NULL;
const char* tokenTable60 = NULL;
const char* tokenTable61 = NULL;
const char* tokenTable62 = NULL;
const char* tokenTable63 = NULL;
const char* tokenTableAA = NULL;
#endif

#if TOKEN_TABLE_7E
const char* tokenTable7E[257] = {
    (char*)0xffffffff,
    "Sequential", "Simul", "PolarGC", "RectGC", "CoordOn", "CoordOff", "Connected", "Dot", "AxesOn", "AxesOff", "GridOn", "GridOff", "LabelOn", "LabelOff", "Web", "Time",
    "uvAxes", "vwAxes", "uwAxes", "npv(", "irr(", "bal(", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};
#else
const char* tokenTable7E = NULL;
#endif

#if TOKEN_TABLE_BB
const char* tokenTableBB[257] = {
    (char*)0xffffffff,
    "npv(", "irr(", "bal(", "SigmaPrn(", "SigmaInt(", ">Nom(", ">Eff(", "dbd(", "lcm(", "gcd(", "randInt(", "randBin(", "sub(", "stdDev(", "variance(", "inString(",
    "normalcdf(", "invNorm(", "tcdf(", "chi^2cdf(", "Fcdf(", "binompdf(", "binomcdf(", "poissonpdf(", "poissoncdf(", "geometpdf(", "geometcdf(", "normalpdf(", "tpdf(", "chi^2pdf(", "Fpdf(", "randNorm(",
    "tvm_pmt", "tvm_I%", "tvm_PV", "tvm_N", "tvm_FV", "conj(", "real(", "imag(", "angle(", "cumSum(", "expr(", "length(", "deltaList(", "ref(", "rref(", ">Rect",
    ">Polar", "e", "SinReg ", "Logistic ", "LinRegTTest ", "ShadeNorm(", "Shade_t(", "Shadechi^2(", "ShadeF(", "Matr>list", "List>matr", "Z-Test(", "T-Test ", "2-SampZTest(", "1-PropZTest(", "2-PropZTest(",
    "chi^2-Test(", "ZInterval ", "2-SampZInt(", "1-PropZInt(", "2-PropZInt(", "GraphStyle(", "2-SampTTest ", "2-SampFTest ", "TInterval ", "2-SampTInt ", "SetUpEditor ", "PMT_End", "PMT_Bgn", "Real", "re^thetai", "a+bi",
    "ExprOn", "ExprOff", "ClrAllLists", "GetCalc(", "DelVar ", "Equ>String(", "String>Equ(", "Clear Entries", "Select(", "ANOVA(", "ModBoxPlot", "NormProbPlot", NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, "G-T", "ZoonFit", "DiagnosticOn", "DiagnosticOff", "Archive ", "UnArchive ", "Asm(", "AsmComp(", "AsmPrgm", NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, "alpha",
    "beta", "gamma", "Delta", "delta", "epsilon", "Lambda", "mu", "pi", "rho", "Sigma", NULL, "phi", "Omega", "phat", "chi", "F",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", NULL, "l", "m", "n", "o",
    "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "sigma", "tau", NULL, "GarbageCollect", "~",
    NULL, "@", "#", "$", "&", "`", ";", "\\", "|", "_", "%", "...", "angle", "Beta", "x", "T",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "<-", "->", "^", "v", NULL,
    "x", "Integral", "up", "down", "sqrt", "blackequals", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};
#else
const char* tokenTableBB = NULL;
#endif

#if TOKEN_TABLE_EF
const char* tokenTableEF[257] = {
    (char*)0xffffffff,
    "setDate(", "setTime(", "checkTmr(", "setDtFmt(", "setTmFmt(", "timeCnv(", "dayOfWk(", "getDtStr(", "getTmStr(", "getDate", "getTime", "startTmr", "getDtFmt", "getTmFmt", "isClockOn", "ClockOff",
    "ClockOn", "OpenLib(", "ExecLib", "invT(", "chi^2GOF-Test(", "LinRegTInt", "Manual-Fit", "ZQuadrant1", "ZFrac1/2", "ZFrac1/3", "ZFrac1/4", "ZFrac1/5", "ZFrac1/8", "ZFrac1/10", "mathprintbox", NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#if TOKEN_TABLE_EF_84PCSE || TOKEN_TABLE_EF_84PCE
    ">n/d<>Un/d", ">F<>D", "remainder(", "Sigma(", "logBASE(", "randIntNoRep(", "MATHPRINT", "CLASSIC", "n/d", "Un/d", "AUTO", "DEC", "FRAC", "FRAC-APPROX", NULL, NULL,
    NULL, "BLUE", "RED", "BLACK", "MAGENTA", "GREEN", "ORANGE", "BROWN", "NAVY", "LTBLUE", "YELLOW", "WHITE", "LTGREY", "MEDGREY", "GREY", "DARKGREY",
    "Image1", "Image2", "Image3", "Image4", "Image5", "Image6", "Image7", "Image8", "Image9", "Image0", "Gridline", "BackgroundOn", NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, "BackgroundOff", "GraphColor(", NULL, "TextColor(", "Asm84CPrgm", NULL, "DetectAsymOn", "DetectAsymOff", "BorderColor", NULL, NULL, NULL,
#else
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#endif
#if TOKEN_TABLE_EF_84PCE
    NULL, NULL, NULL, "tinydotplot", "Thin", "Dot-Thin", NULL, NULL, NULL, "PlySmth2", "Asm84CEPrgm", NULL, NULL, NULL, NULL, NULL,
    NULL, "Quartiles Setting...", "u(n-2)", "v(n-2)", "w(n-2)", "u(n-1)", "v(n-1)", "w(n-1)", "u(n)", "v(n)", "w(n)", "u(n+1)", "v(n+1)", "w(n+1)", "pieceWise(", "SEQ(n)",
    "SEQ(n+1)", "SEQ(n+2)", "LEFT", "CENTER", "RIGHT", "invBinom(", "Wait", "toString(", "eval", NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#else
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#endif
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};
#else
const char* tokenTableEF = NULL;
#endif

const char* mainTokenTable[256] = {
    NULL, ">DMS", ">Dec", ">Frac", "->", "BoxPlot", "[", "]", "{", "}", "^r", "º", "^-1", "^2", "^T", "^3",
    "(", ")", "round(", "pxl-Test(", "augment(", "rowSwap(", "row+(", "*row(", "*row+(", "max(", "min(", "R>Pr(", "R>PTheta(", "P>Rx(", "P>Ry(", "median(",
    "randM(", "mean(", "solve(", "seq(", "fnInt(", "nDeriv(", NULL, "fMin(", "fMax(", " ", "\"", ",", "i", "!", "CubicReg ", "QuartReg ",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "E", " or ", " xor ", ":", "\r",
    " and ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Theta", (char*)tokenTable5C, (char*)tokenTable5D, (char*)tokenTable5E, "prgm",
    (char*)tokenTable60, (char*)tokenTable61, (char*)tokenTable62, (char*)tokenTable63, "Radian", "Degree", "Normal", "Sci", "Eng", "Float", "=", "<", ">", "<=", ">=", "=/=",
    "+", "-", "Ans", "Fix ", "Horiz", "Full", "Func", "Param", "Polar", "Seq", "IndpntAuto", "IndpntAsk", "DependAuto", "DependAsk", (char*)tokenTable7E, "[box]",
    "[+]", "[.]", "*", "/", "Trace", "ClrDraw", "ZStandard", "ZTrig", "ZBox", "Zoom In", "Zoom Out", "ZSquare", "ZInteger", "ZPrevious", "ZDecimal", "ZoomStat",
    "ZoomRcl", "PrintScreen", "ZoomSto", "Text(", " nPr ", " nCr ", "FnOn ", "FnOff ", "StorePic ", "RecallPic ", "StoreGDB ", "RecallGDB ", "Line(", "Vertical ", "Pt-On(", "Pt-Off(",
    "Pt-Change(", "Pxl-On(", "Pxl-Off(", "Pxl-Change(", "Shade(", "Circle(", "Horizontal ", "Tangent(", "DrawInv ", "DrawF ", (char*)tokenTableAA, "rand", "pi", "getKey", "'", "?",
    "-", "int(", "abs(", "det(", "identity(", "dim(", "sum(", "prod(", "not(", "iPart(", "fPart(", (char*)tokenTableBB, "sqrt(", "cbrt(", "ln(", "e^(",
    "log(", "10^(", "sin(", "sin^-1(", "cos(", "cos^-1(", "tan(", "tan^-1(", "sinh(", "sinh^-1(", "cosh(", "cosh^-1(", "tanh(", "tanh^-1(", "If ", "Then",
    "Else", "While ", "Repeat ", "For(", "End", "Return", "Lbl ", "Goto ", "Pause ", "Stop", "IS>(", "DS>(", "Input ", "Prompt ", "Disp ", "DispGraph",
    "Output(", "ClrHome", "Fill(", "SortA(", "SortD(", "DispTable", "Menu(", "Send(", "Get(", "PlotsOn ", "PlotsOff ", "L", "Plot1(", "Plot2(", "Plot3(", (char*)tokenTableEF,
    "^", "xrt(", "1-Var Stats ", "2-Var Stats ", "LinReg(a+bx) ", "ExpReg ", "LnReg ", "PwrReg ", "Med-Med ", "QuadReg ", "ClrList ", "ClrTable", "Histogram", "xyLine", "Scatter", "LinReg(ax+b)"
};
