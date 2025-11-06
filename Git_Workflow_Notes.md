# Git Workflow Notes

**Author:** QLKang
**Date:** November 2025
**Purpose:** Record the complete Git workflow used for managing Arduino projects.

---

## 🧭 1. Navigate to Project Directory

```bash
cd ~/Documents/Arduino_Projects
```

**Explanation:**
Move to the main working directory that contains all Arduino project folders.
(Your actual path on Mac is `/Users/ring/Documents/Arduino_Projects`.)

---

## 🪄 2. Add a New Project and Push to GitHub

```bash
# Check current directory contents
ls

# Add the entire project folder to the staging area
git add 2025_10_30_Button_toggle_debounce/

# Commit the added files
git commit -m "Add Button Toggle Debounce project properly"

# Push the changes to GitHub main branch
git push origin main
```

**Explanation:**

* `git add` — stage the new files for commit.
* `git commit` — create a snapshot of your changes.
* `git push` — upload the commit to your GitHub repository.

---

## 🧱 3. Update Existing Files (README, Images, etc.)

```bash
# Check what has changed
git status

# Add all modified files
git add .

# Commit with a clear message
git commit -m "Update README and docs for Button Toggle Debounce project"

# Push updates to GitHub
git push origin main
```

**Explanation:**
Use this sequence whenever you modify any files (e.g., README.md or images).
`git add .` adds all changes under the current directory.

---

## ⏰ 4. Refresh Commit Time on GitHub

If the GitHub page still shows an older timestamp, refresh it by amending the commit date:

```bash
# Make sure you are on the main branch
git checkout main

# Amend the latest commit with the current date/time
git commit --amend --no-edit --date="$(date)"

# Force push to update the commit timestamp on GitHub
git push origin main --force
```

**Explanation:**

* `--no-edit` keeps the same commit message.
* `--date="$(date)"` resets the commit time to "now".
* `--force` overwrites the remote commit (safe in your own repo).

---

## 📜 5. Useful Commands Summary

| Command                   | Description                               |
| ------------------------- | ----------------------------------------- |
| `git log -1`              | Show the most recent commit details       |
| `git status`              | Check file modification status            |
| `git diff`                | Display content differences before commit |
| `git restore <file>`      | Undo changes in a specific file           |
| `git push -u origin main` | Set upstream branch for the first push    |
| `git pull`                | Fetch and merge updates from GitHub       |

---

## 💡 Tips

* Always write meaningful commit messages.
* Use `git status` frequently to track what will be committed.
* Keep your `.gitignore` file clean to avoid committing temporary files (like `.DS_Store`).
* Regularly push small commits instead of one big batch.

---

**End of Notes**


