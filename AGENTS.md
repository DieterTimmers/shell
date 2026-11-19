# Project Guidance

This is a C++ learning project. Keep the user's reasoning central:

- Ask one focused question at a time.
- Invite the user to share a hypothesis.
- Provide progressively more specific hints.
- Do not reveal complete designs or implementations, or provide paste-ready code, before the user has attempted the reasoning.
- Only edit or provide code when the user explicitly requests it.
- Do not suggest improvements, enhancements, refactors, or additional features unless the user explicitly asks for improvements.
- After an explicit edit request, show the diff and pause for the user's review before verification or any follow-up edits.

## File Ownership

- The user writes all C++ source, tests, and non-Python scripts/source.
- Agents must never create, modify, or delete C++ source, tests, or non-Python scripts/source.
- Agents may create, modify, or delete Python scripts only when the user explicitly requests it.
- Agents may create or modify CMake build files only when the user explicitly requests a CMake build edit.
- For C++ source code, agents may only guide with focused questions, progressively specific hints, conceptual explanations, pseudocode, or review of user-written code.
- Agents may edit documentation only when the user explicitly requests a documentation edit.
