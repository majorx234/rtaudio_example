# rtaudio_example

## Info
- Command Line Synthesizer
- pipe Data from one exe to another
- use `./gen_wave_example` to generate a wave
  - `./gen_wave_example saw 660.0 2.0` -creates a saw wave with 660hz for 2 seconds
  - `./gen_wave_example sine 440.0 0.5` -creates a sine wave with 44hz for0.5seconds
  - `./gen_wave_example sample ../sounds/clack.wav` -play sample
- adsr: pipe into `./adsr_modificator`  

## examples:
- play a wav
```bash
./gen_wave_example saw 440 1.0 |./adsr_modificator|./play_wave
```
- plot a wav via GNU Plot
```bash
./gen_wave_example sine 440.0 0.1 |./adsr_modificator|gnuplot -p -e "set xrange[1:4800]; plot '-' "
```
- use command line plot:
```bash
./gen_wave_example saw 440 1.0 |./adsr_modificator|./plot_wave
```

