

bool checkInclusion(char* s1, char* s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    
    if (l1 > l2) return false;

    // Expand arrays to 256 to cover every possible byte value safely
    int h1[256] = {0};
    int h2[256] = {0};
    
    for (int i = 0; i < l1; i++) {
       // Using (unsigned char) guarantees a safe index between 0 and 255
       h1[(unsigned char)s1[i]]++;
       h2[(unsigned char)s2[i]]++;
    }
    
    if (memcmp(h1, h2, sizeof(h1)) == 0) return true;

    for (int i = l1; i < l2; i++) {
        // Add character entering from the right edge
        h2[(unsigned char)s2[i]]++;

        // Remove character exiting from the left edge
        h2[(unsigned char)s2[i - l1]]--;

        if (memcmp(h1, h2, sizeof(h1)) == 0) return true;
    }

    return false;
}
