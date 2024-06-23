def compute_lps(pattern):
    m = len(pattern)
    lps = [0] * m
    length = 0
    i = 1
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    
    return lps
def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    lps = compute_lps(pattern)
    i = 0
    j = 0
    occurrences = []
    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1
        if j == m:
            occurrences.append(i - j)
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return occurrences
text = input("Enter the text: ")
pattern = input("Enter the pattern to search for: ")
result = kmp_search(text, pattern)
if result:
    print(f"Pattern '{pattern}' found at indices: {result}")
else:
    print(f"Pattern '{pattern}' not found in the text.")
