# Arduino Projects

## 项目列表
1. Button Toggle with Debounce (2025-10-30)
## Git Commands Notes

This section summarizes the Git workflow used for managing Arduino projects.

### 1. Navigate to Project Directory
```bash
cd ~/Documents/Arduino_Projects

### 2. Add a New Project and Push
git add <project-folder>   # e.g., git add 2025_10_30_Button_toggle_debounce/
git commit -m "Add <Project Name>"
git push origin main

### 3. Update Existing Files
git add .                  # stage all modified files
git commit -m "Update README and docs for <Project Name>"
git push origin main

### 4. Refresh Commit Time on GitHub
git commit --amend --no-edit --date="$(date)"
git push origin main --force

5. Useful Commands
Command	Description
git status	Check file modifications
git log -1	Show the most recent commit
git diff	Show content differences
git restore <file>	Undo changes in a file
git push -u origin main	Set upstream branch (first push)
git pull	Pull latest changes from GitHub
