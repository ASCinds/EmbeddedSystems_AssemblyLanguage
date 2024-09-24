void setup() {
    Serial.begin(9600);

    asm volatile(
        "ldi r18, 0xFC;\n"
        "out 4, r18;\n"
        ::: "r18");
}

void loop() {

    // Traffic green and red light 
    asm volatile(
        "ldi r18, 0x90;\n"
        "out 5, r18;\n"
        "call delay;\n"
    );

    // Traffic amber and amber light
    asm volatile(
        "ldi r18, 0x48;\n"
        "out 5, r18;\n"
        "call delay;\n"
    );

    // Traffic red and green light
    asm volatile(
        "ldi r18, 0x24;\n"
        "out 5, r18;\n"
        "call delay;\n"
    );

   // read amber and red amber light
    asm volatile(
        "ldi r18, 0x78;\n"
        "out 5, r18;\n"
        "call delay;\n"
    );
}

// Nested loops for delay
asm volatile(
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
