Pulsing LEDs sketch for Arduino, aimed to look a bit like Apple's
sleep mode LED 

I initially tried sin(t), for t in (0, pi), but I found that
1 - |cos(t)| looks better.
