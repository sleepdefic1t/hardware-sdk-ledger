// import "jest-extended";
// import { ARKTransport } from "ledger-transport-ark";
// import { APP_PATH, ZEMU_OPTIONS } from "./constants";
// const Zemu = require('@zondax/zemu').default;

// jest.setTimeout(100000);

// describe("signTransactionWithSchnorr", () => {
// 	it("should pass with a schnorr signature", async () => {
// 		const sim = new Zemu(APP_PATH);

// 		try {
// 			await sim.start(ZEMU_OPTIONS);
// 			const app = new ARKTransport(sim.getTransport());

// 			const path = "44'/111'/0'/0/0";
// 			const transactionBuffer = Buffer.from("ff0217010000000000010000000000000003a02b9d5fdd1307c2ee4652ba54d492d1fd11a7d1bb3f3a44c4a05e79f19de933809698000000000000a08601000000000000000000171dfc69b54c7fe901e91d5a9ab78388645e2427ea", "hex");

// 			// do not await here..
// 			const signatureRequest = app.signTransactionWithSchnorr(path, transactionBuffer);

// 			await Zemu.sleep(2000);

// 			// Reference window
// 			for (let i = 0; i < 7; i++) {
// 				await sim.clickRight();
// 			}
// 			await sim.clickBoth();

// 			const response = await signatureRequest

// 			// The emulated zemu/speculos signatures aren't deterministic here for some reason.
// 			// for now, let's just check that the response is not empty.
// 			expect(response).not.toBe('');
// 		} catch (e) {
// 			console.error(e);
// 		} finally {
// 			await sim.close();
// 		}
// 	});
// });
