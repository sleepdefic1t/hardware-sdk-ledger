import "jest-extended";
import { ARKTransport } from "ledger-transport-ark";
import { APP_PATH, ZEMU_OPTIONS } from "./constants";
const Zemu = require('@zondax/zemu').default;

jest.setTimeout(100000);

describe("getVersion", () => {
	it("should pass with an app version", async () => {
		const sim = new Zemu(APP_PATH);
		try {
			await sim.start(ZEMU_OPTIONS);
			const app = new ARKTransport(sim.getTransport());

			const appVersion = "2.1.0";

			await expect(app.getVersion()).resolves.toEqual(appVersion);
		} catch (e) {
			console.error(e);
		} finally {
			await sim.close();
		}
	});
});
