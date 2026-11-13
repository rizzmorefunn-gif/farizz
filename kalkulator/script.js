const form = document.querySelector("#calculator-form");
const firstNumberInput = document.querySelector("#first-number");
const secondNumberInput = document.querySelector("#second-number");
const firstBaseInput = document.querySelector("#first-base");
const secondBaseInput = document.querySelector("#second-base");
const operatorInput = document.querySelector("#operator");
const errorMessage = document.querySelector("#error-message");
const outputs = {
  2: document.querySelector("#result-binary"),
  8: document.querySelector("#result-octal"),
  10: document.querySelector("#result-decimal"),
  16: document.querySelector("#result-hexadecimal"),
};

function parseInteger(value, base) {
  const normalized = value.trim().toLowerCase();
  const isNegative = normalized.startsWith("-");
  const digits = isNegative || normalized.startsWith("+")
    ? normalized.slice(1)
    : normalized;

  if (!digits) {
    throw new Error("Masukkan bilangan yang tidak kosong.");
  }

  let result = 0n;
  for (const character of digits) {
    const digit = Number.parseInt(character, 36);
    if (!Number.isInteger(digit) || digit >= base) {
      throw new Error(
        `Angka "${character}" tidak valid untuk basis ${base}.`,
      );
    }
    result = result * BigInt(base) + BigInt(digit);
  }

  return isNegative ? -result : result;
}

function calculate(first, second, operator) {
  switch (operator) {
    case "+":
      return first + second;
    case "-":
      return first - second;
    case "*":
      return first * second;
    case "/":
      if (second === 0n) {
        throw new Error("Bilangan tidak dapat dibagi dengan nol.");
      }
      return first / second;
    default:
      throw new Error("Operasi yang dipilih tidak dikenal.");
  }
}

function clearResults() {
  for (const output of Object.values(outputs)) {
    output.value = "—";
  }
}

form.addEventListener("submit", (event) => {
  event.preventDefault();
  errorMessage.hidden = true;
  errorMessage.textContent = "";

  try {
    const first = parseInteger(firstNumberInput.value, Number(firstBaseInput.value));
    const second = parseInteger(secondNumberInput.value, Number(secondBaseInput.value));
    const result = calculate(first, second, operatorInput.value);

    for (const [base, output] of Object.entries(outputs)) {
      output.value = result.toString(Number(base)).toUpperCase();
    }
  } catch (error) {
    clearResults();
    errorMessage.textContent = error.message;
    errorMessage.hidden = false;
  }
});

form.addEventListener("reset", () => {
  errorMessage.hidden = true;
  errorMessage.textContent = "";
  clearResults();
});
