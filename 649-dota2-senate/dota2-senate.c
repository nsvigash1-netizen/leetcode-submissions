char* predictPartyVictory(char* senate) {
    int len = strlen(senate);

    int *R = (int*)malloc(len * 2 * sizeof(int));
    int *D = (int*)malloc(len * 2 * sizeof(int));
    int rHead = 0, rTail = 0;
    int dHead = 0, dTail = 0;

    // Populate queues with initial indices
    for (int i = 0; i < len; i++) {
        if (senate[i] == 'R')
            R[rTail++] = i;
        else
            D[dTail++] = i;
    }

    // Simulate rounds
    while (rHead < rTail && dHead < dTail) {
        int rIdx = R[rHead++];
        int dIdx = D[dHead++];

        if (rIdx < dIdx)
            R[rTail++] = rIdx + len;  // R senator wins, rejoins next round
        else
            D[dTail++] = dIdx + len;  // D senator wins, rejoins next round
    }

    free(R);
    free(D);
    return (rHead < rTail) ? "Radiant" : "Dire";
}
