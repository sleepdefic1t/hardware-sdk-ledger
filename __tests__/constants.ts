const Resolve = require("path").resolve;

export const APP_PATH = Resolve("packages/ledger-app-ark/bin/app.elf");
export const APP_SEED = "this is a top secret passphrase";

export const ZEMU_OPTIONS = {
	logging: false,
	start_delay: 3000,
	custom: `-s "${APP_SEED}" `,
	// custom: `-s "${APP_SEED}" --debug`,
	// X11: true,
};
