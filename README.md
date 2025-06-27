````markdown
# 🧪 CodeChecker Static Analysis Project

## 📌 Overview

This project demonstrates **static code analysis** of a C-language program (`todo_list.c`) using [**CodeChecker**](https://github.com/Ericsson/codechecker), a powerful tool built on top of Clang. The project ensures code quality, detects bugs, and verifies security issues using multiple analyzers: `clangsa`, `cppcheck`, and `clang-tidy`.

> 🔒 Static analysis is a key part of secure software development (SSDLC) and CI pipelines.

---

## 📂 Project Structure

```bash
.
├── todo_list.c              # C source file under analysis
├── todo_list                # Compiled binary
├── compile_commands.json    # Compilation database (generated via Bear)
├── reports/                 # Output folder with analysis results
├── analyze_output.txt       # Raw text output of 'codechecker analyze'
├── parse_output.txt         # Raw text output of 'codechecker parse'
├── analyze_output.md        # Formatted Markdown analysis log
├── parse_output.md          # Formatted Markdown parse log
````

---

## ⚙️ Tools Used

| Tool          | Purpose                                     |
| ------------- | ------------------------------------------- |
| `CodeChecker` | Static code analysis frontend               |
| `clangsa`     | Detects bugs like null dereference, leaks   |
| `clang-tidy`  | Detects code style issues and anti-patterns |
| `cppcheck`    | Checks for logic bugs and memory issues     |
| `Bear`        | Generates `compile_commands.json`           |

---

## 🚀 How to Run

1. **Compile with Bear:**

   ```bash
   bear -- gcc todo_list.c -o todo_list
   ```

2. **Run CodeChecker analysis:**

   ```bash
   codechecker analyze compile_commands.json -o ./reports
   ```

3. **Parse the analysis result:**

   ```bash
   codechecker parse ./reports
   ```

4. *(Optional)* Store and view via Web UI:

   ```bash
   codechecker store ./reports -n my_analysis
   codechecker server
   # Visit: http://localhost:8001
   ```

---

## 🧠 Key Skills Demonstrated

* Static analysis tooling and integration
* Code quality and security auditing in C
* Use of modern analyzer frameworks (`clang-tidy`, `cppcheck`)
* Compilation database generation with Bear
* Command-line automation and report generation

---

## 🗒️ Sample Output

> 📄 See `analyze_output.md` and `parse_output.md` for full analysis logs.

---

## 🏁 Result

No issues were found by any analyzer across:

* `clangsa`
* `clang-tidy`
* `cppcheck`

✅ The code passed a full static audit.

---

## 🔐 Potential Improvements

* Add CI integration (e.g. GitHub Actions)
* Extend analysis to larger codebases
* Apply security-focused rulesets
* Export results in SARIF format

---

## 📜 License

This project is for educational and personal learning purposes.
