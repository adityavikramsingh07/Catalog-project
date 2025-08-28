This project implements Shamir’s Secret Sharing (SSS) concept using Lagrange Interpolation.
The goal is to recover the hidden constant term c (the secret) of a polynomial from given roots in a JSON test case.

🚀 Features

Reads input from a JSON file (input.json)

Decodes encoded y-values given in different bases

Uses Lagrange Interpolation to reconstruct the polynomial

Recovers the constant term (c), which is the secret

🛠️ Tech Stack

Language: C++17

Libraries:

nlohmann/json
 (for JSON parsing)

Standard Template Library (STL)
Output for Test case 1 :
(1, 4), (2, 7), (3, 12), (6, 39)
