bool lemonadeChange(int* bills, int billsSize) {
    int cinco = 0;
    int dez = 0;

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            cinco++;
        } else if (bills[i] == 10) {
            if (cinco == 0) {
                return false;
            }
            cinco--;
            dez++;

        } else {
            if (dez > 0 && cinco > 0) {
                dez--;
                cinco--;
            } else if (cinco >= 3) {
                cinco -= 3;
            } else {
                return false;
            }
        }
        if (cinco < 0) {
            return false;
        }
    }
    return true;
}