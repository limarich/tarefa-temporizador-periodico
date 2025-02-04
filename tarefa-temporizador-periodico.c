#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define RED_PIN 13
#define GREEN_PIN 11
#define YELLOW_PIN 12
#define INTERVAL 3000 // 3 segundos de intervalo entre as ações

int current_pin = RED_PIN;

void setup_pin(uint gpio)
{
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

bool repeating_timer_callback(struct repeating_timer *t)
{
    if (current_pin == RED_PIN)
    {
        gpio_put(RED_PIN, true);
        gpio_put(GREEN_PIN, false);
        gpio_put(YELLOW_PIN, false);

        // indica qual o próximo pino a ser ligado
        current_pin = YELLOW_PIN;
    }
    else if (current_pin == YELLOW_PIN)
    {
        gpio_put(RED_PIN, false);
        gpio_put(GREEN_PIN, false);
        gpio_put(YELLOW_PIN, true);

        // indica qual o próximo pino a ser ligado
        current_pin = GREEN_PIN;
    }
    else if (current_pin == GREEN_PIN)
    {
        gpio_put(RED_PIN, false);
        gpio_put(GREEN_PIN, true);
        gpio_put(YELLOW_PIN, false);

        // indica qual o próximo pino a ser ligado
        current_pin = RED_PIN;
    }
};

int main()
{
    struct repeating_timer timer;

    stdio_init_all();

    // configura os pinos
    setup_pin(RED_PIN);
    setup_pin(GREEN_PIN);
    setup_pin(YELLOW_PIN);

    // garante que começará no led vermelho ligado antes do callback
    gpio_put(RED_PIN, true);
    gpio_put(GREEN_PIN, false);
    gpio_put(YELLOW_PIN, false);
    current_pin = YELLOW_PIN;

    // configura o timer
    add_repeating_timer_ms(INTERVAL, repeating_timer_callback, NULL, &timer);

    while (true)
    {
        printf("Olá, embarcatech!\n");
        sleep_ms(1000);
    }
}
