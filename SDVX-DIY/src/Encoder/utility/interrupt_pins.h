// interrupt pins for Arduino Leonardo

// Arduino Leonardo
#if defined(__AVR_ATmega32U4__)
  #define CORE_NUM_INTERRUPT	4
  #define CORE_INT0_PIN		3
  #define CORE_INT1_PIN		2
  #define CORE_INT2_PIN		0
  #define CORE_INT3_PIN		1

#endif
#endif

#if !defined(CORE_NUM_INTERRUPT)
#error "Interrupts are unknown for this board, please add to this code"
#endif
#if CORE_NUM_INTERRUPT <= 0
#error "Encoder requires interrupt pins, but this board does not have any :("
#error "You could try defining ENCODER_DO_NOT_USE_INTERRUPTS as a kludge."
#endif

