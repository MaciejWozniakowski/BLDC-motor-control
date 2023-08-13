struct derivative{
    float angle_1;
    float delta_t;
    float output;
};

void derivative_calc(struct derivative *dv, float angle);
void derivative_init(struct derivative *dv, float delta_t);
