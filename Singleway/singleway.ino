void setup() {

 
  asm volatile(
    "ldi r18, 0xE0;\n" // 0b11100000
    "out 4, r18;\n"
    ::: "r18"
  );
}

void loop() {
  // green light high others low
  asm volatile ( 
    "ldi r18, 0x80;\n" // 0b10000000
    "out 5, r18;\n"
    "call delay;\n"
  );

  // amber light high and others low
  asm volatile ( 
    "ldi r18, 0x40;\n" // 0b01000000
    "out 5, r18;\n"
    "call delay;\n"
  );

  // red light high and others low 
  asm volatile (  
    "ldi r18, 0x20;\n" // 0b00100000
    "out 5, r18;\n"
    "call delay;\n"
  );

  // red and amber light high and others low
  asm volatile(
    "ldi r18, 0x60;\n" // 0b01100000
    "out 5, r18;\n"
    "call delay;\n"
  );
}

// loops for the delay
asm volatile (
  "delay:\n"
  "ldi r23, 0xFF;\n" // outer loop
  "third_loop:\n"
  "ldi r24, 0xFF;\n" // middle loop
  "second_loop:\n"
  "ldi r25, 0xFF;\n" // inner loop
  "innermost_loop:\n"
  "dec r25;\n"
  "brne innermost_loop;\n"
  "dec r24;\n"
  "brne second_loop;\n"
  "dec r23;\n"
  "brne third_loop;\n"
  "ret ;\n"
);

