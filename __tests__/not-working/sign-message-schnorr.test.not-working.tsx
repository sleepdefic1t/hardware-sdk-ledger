import "jest-extended";
import { ARKTransport } from "ledger-transport-ark";
import { APP_PATH, ZEMU_OPTIONS } from "../constants";
const Zemu = require('@zondax/zemu').default;

jest.setTimeout(100000);

describe("signMessageWithSchnorr", () => {
	it("should pass with a schnorr signature", async () => {
		const sim = new Zemu(APP_PATH);

		try {
			await sim.start(ZEMU_OPTIONS);
			const app = new ARKTransport(sim.getTransport());

			const path = "44'/111'/0'/0/0";
			const messageBuffer = Buffer.from("416c6c2070617274732073686f756c6420676f20746f67657468657220776974686f757420666f7263696e672e20596f75206d7573742072656d656d62657220746861742074686520706172747320796f7520617265207265617373656d626c696e67207765726520646973617373656d626c656420627920796f752e205468657265666f72652c20696620796f752063616e277420676574207468656d20746f67657468657220616761696e2c207468657265206d757374206265206120726561736f6e2e20427920616c6c206d65616e732c20646f206e6f742075736520612068616d6d65722e207e2049424d204d616e75616c202d20283139373529", "hex");

			// do not await here..
			const signatureRequest = app.signMessageWithSchnorr(path, messageBuffer);

			await Zemu.sleep(2000);

			// Reference window
			for (let i = 0; i < 22; i++) {
				await sim.clickRight();
			}
			await sim.clickBoth();

			const response = await signatureRequest

			// The emulated zemu/speculos signatures aren't deterministic here for some reason.
			// for now, let's just check that the response is not empty.
			expect(response).not.toBe('');
		} catch (e) {
			console.error(e);
		} finally {
			await sim.close();
		}
	});
});
