import "jest-extended";
import { ARKTransport } from "ledger-transport-ark";
import { APP_PATH, ZEMU_OPTIONS } from "./constants";
const Zemu = require('@zondax/zemu').default;

jest.setTimeout(100000);

describe("getPublicKey", () => {
	it("should pass with a compressed publicKey", async () => {
		const sim = new Zemu(APP_PATH);
		try {
			await sim.start(ZEMU_OPTIONS);
			const app = new ARKTransport(sim.getTransport());

			const path = "44'/111'/0'/0/0";
			const publicKeyHex = "037f58d0de374d494fc1e2c851180866beb5287da67f4b1c5beacbb1da377c7f25";

			await expect(app.getPublicKey(path)).resolves.toEqual(publicKeyHex);
		} catch (e) {
			console.error(e);
		} finally {
			await sim.close();
		}
	});
});
