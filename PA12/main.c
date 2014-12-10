int main(int argc, char * * argv)
{
    const char * str = "340282366920938463463374607431768211455";
    uint128 w = alphaTou128(str);
    char * w_str = u128ToString(w);
    printf("Biiigggg number: %s\n", w_str);
    if(strcmp(str, w_str) != 0)
       printf("ERROR!, expected %s\n", str);
    free(w_str);
    return EXIT_SUCCESS;
}
