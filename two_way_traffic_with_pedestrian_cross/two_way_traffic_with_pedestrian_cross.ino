volatile bool serialInputReceived = false;

void setup() {
  Serial.begin(9600);
  // Some AVR assembly code here
  // ...
  asm volatile(
    "ldi r18, 0xFF;\n"
    "out 4, r18;\n"
    ::: "r18"
  );
}

void loop() {
  if (Serial.available()) {
    char inputChar = Serial.read();
    if (inputChar == 'start') {
      Serial.println("ncc");
      
      asm volatile(
        "ldi r18, 0x31;\n"
        "out 5, r18;\n"
        "call delay;\n"
        "call delay;\n"
        "call delay;\n"
      );
    }
    else {
      Serial.println("Invalid input. Enter 'start' to start the sequence.");
    }
  }
  
  // PHASE 1
  asm volatile ( 
    "ldi r18, 0x92;\n"
    "out 5, r18;\n"
    "call delay;\n"
  );

  // PHASE 2
  asm volatile ( 
    "ldi r18, 0x4A;\n"
    "out 5, r18;\n"
    "call delay;\n"
  );

  // PHASE 3
  asm volatile (  
    "ldi r18, 0x26;\n"
    "out 5, r18;\n"
    "call delay;\n"
  );

  // PHASE 4
  asm volatile(
    "ldi r18, 0x7A;\n"
    "out 5, r18;\n"
    "call delay;\n"
    "call delay;\n"
    
  );
}

// Nested loops for delay
asm volatile (
"delay:\n"
  "ldi r23, 0x64;\n" // outer loop
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


