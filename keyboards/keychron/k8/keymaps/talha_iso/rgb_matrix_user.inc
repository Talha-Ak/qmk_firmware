RGB_MATRIX_EFFECT(custom_boot_anim)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Define custom values if not defined in config.h
#if STARTUP_ANIM_TIME < 0
#   error STARTUP_ANIM_TIME must be greater than 0
#elif !defined (STARTUP_ANIM_TIME)
#   define STARTUP_ANIM_TIME 2200
#endif

#if !defined (ENABLE_RGB_MATRIX_SPLASH) && !defined (ENABLE_RGB_MATRIX_MULTISPLASH)
    // Splash animation math
    HSV SPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
        uint16_t effect = tick - dist;
        if (effect > 255) effect = 255;
        hsv.h += effect;
        hsv.v = qadd8(hsv.v, 255 - effect);
        return hsv;
    }
#endif

#if defined (ENABLE_RGB_MATRIX_SPLASH) || defined (ENABLE_RGB_MATRIX_MULTISPLASH)
    HSV SPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick);
#endif

static uint16_t boot_timer;
static bool custom_boot_anim(effect_params_t* params) {
    if (params->init) boot_timer = timer_read();
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    if (timer_elapsed(boot_timer) >= STARTUP_ANIM_TIME) {
        rgb_matrix_set_speed_noeeprom(rgb_matrix_config.speed);                                             // Reset speed to original value
        eeprom_read_block(&rgb_matrix_config, EECONFIG_RGB_MATRIX, sizeof(rgb_matrix_config));
        rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);                                                   // Load original mode
        return false;
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        HSV hsv       = rgb_matrix_config.hsv;
        hsv.v         = 0;
        int16_t  dx   = g_led_config.point[i].x - 3; 
        int16_t  dy   = g_led_config.point[i].y - 26;
        uint8_t  dist = sqrt16(dx * dx + dy * dy);
        uint16_t tick = scale16by8(timer_elapsed(boot_timer), qadd8(rgb_matrix_config.speed, 1));
        hsv           = SPLASH_math(hsv, dx, dy, dist, tick);
        hsv.v         = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif
