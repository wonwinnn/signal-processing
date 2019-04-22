function envlop(s, n)

signal = s;
w = hamming(length(signal));
winsignal = w.*signal;
sspec = fft(winsignal);
logsspec = log(abs(sspec));
rcep = real(ifft(logsspec));
wzp = [ones(n,1);zeros(length(rcep)-2*n,1);ones(n,1)];
%wzp = ones(length(rcep),1);
wrcep = wzp.*rcep;
rcepenv = real(fft(wrcep));
nrcepenv = rcepenv-mean(rcepenv);
plot(nrcepenv);hold on;plot(logsspec, 'r');