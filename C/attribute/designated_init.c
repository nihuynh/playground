struct s1 {
	int x;
	int y;
};

struct s2 {
	int x;
	int y;
} __attribute__((designated_init));


int main(void) {
    [[gnu::unused]]
    struct s1 s1_positional = { 5, 10 };
    [[gnu::unused]]
    struct s1 s1_designated = { .x = 5, .y = 10 };
    [[gnu::unused]]
    struct s2 s2_positional = { 5, 10 };
    [[gnu::unused]]
    struct s2 s2_designated = { .x = 5, .y = 10 };
    return (0);
}